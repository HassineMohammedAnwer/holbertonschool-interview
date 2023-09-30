#!/usr/bin/node
const request = require('request');
const ap = `https://swapi-api.hbtn.io/api/films/`;
request.get(ap + process.argv[2], async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;

    for (const chr in characters) {
      try {
        const res = await new Promise((resolve, reject) => {
          request(characters[chr], (error, res, html) => {
            if (error) {
              reject(error);
            } else {
              resolve(JSON.parse(html).name);
            }
          });
        });
        console.log(res);
      } catch (err) {
        console.error(err);
      }
    }
  }
});

