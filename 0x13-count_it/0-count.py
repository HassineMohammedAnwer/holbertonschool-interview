#!/usr/bin/python3
"""recurively
queries the Reddit API"""
import requests


def count_words(subreddit, word_list, counts=None, after=None):
    """prints a sorted count
    of given keywords"""
    if counts is None:
        counts = {}
    word_list = [word.lower() for word in word_list]

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    # 'Mozilla/5.0': to avoid being blocked by Reddit
    headers = {'User-Agent': 'Mozilla/5.0'}
    params = {'limit': 100, 'after': after}
    response = requests.get(url,
                            headers=headers,
                            params=params,
                            allow_redirects=False)
    if response.status_code != 200:
        return
    data = response.json().get('data')
    after = data.get('after')
    posts = data.get('children')

    for post in posts:
        title = post.get('data').get('title').lower()
        for word in word_list:
            counts[word] = counts.get(word, 0) + title.split().count(word)

    if after is not None:
        return count_words(subreddit, word_list, counts, after)
    # 1. Sort by count in descending order
    # 2. Sort alphabetically by word in ascending order
    sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0].lower()))
    for word, count in sorted_counts:
        if count > 0:
            print(f'{word.lower()}: {count}')
    return counts
