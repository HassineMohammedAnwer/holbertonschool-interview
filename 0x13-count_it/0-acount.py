#!/usr/bin/python3
import requests

def count_words(subreddit, word_list, after=None, counts={}):
    headers = {'User-Agent': 'MyBot/1.0'}  # Replace 'MyBot/1.0' with your bot's user agent

    if after is None:
        url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    else:
        url = f'https://www.reddit.com/r/{subreddit}/hot.json?after={after}'

    response = requests.get(url, headers=headers)

    if response.status_code != 200:
        return

    data = response.json()
    children = data.get('data', {}).get('children', [])

    for child in children:
        title = child.get('data', {}).get('title', '').lower()
        for word in word_list:
            # Check for a valid match and exclude variations
            if (word.lower() in title) and not title.startswith(word.lower() + '.'):
                counts[word.lower()] = counts.get(word.lower(), 0) + 1

    after = data.get('data', {}).get('after')

    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            print(f'{word}: {count}')
