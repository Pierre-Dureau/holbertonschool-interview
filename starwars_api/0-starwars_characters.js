#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function doRequest (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(JSON.parse(body));
      }
    });
  });
}

async function main () {
  try {
    const filmData = await doRequest(url);

    for (const characterURL of filmData.characters) {
      try {
        const characterData = await doRequest(characterURL);
        console.log(characterData.name);
      } catch (error) {
        console.error('Erreur:', error);
      }
    }
  } catch (error) {
    console.error('Erreur:', error);
  }
}

main();
