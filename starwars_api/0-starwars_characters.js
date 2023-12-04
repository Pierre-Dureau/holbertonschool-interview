#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function doRequest(url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
        resolve(JSON.parse(body));
    });
  });
}

async function main() {
    const filmData = await doRequest(url);
    for (const characterURL of filmData.characters) {
        const characterData = await doRequest(characterURL);
        console.log(characterData.name);
    }
}

main();
