#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(url, (error, response, body) => {
  if (error) {
    console.error('Erreur:', error);
  } else {
    const data = JSON.parse(body);
    data.characters.forEach(character => {
      request(character, (error, response, body) => {
        if (error) {
          console.error('Erreur:', error);
        } else {
          console.log(JSON.parse(body).name);
        }
      });
    });
  }
});
