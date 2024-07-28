const http = require('http');
const querystring = require('querystring');
const fs = require('fs');

// ... (rest of your server code)

if (url === '/api/upload' && method === 'POST') {
  let body = '';
  req.on('data', chunk => {
    body += chunk.toString();
  });
  req.on('end', () => {
    const parsedBody = JSON.parse(body);
    const imageData = parsedBody.image;
    const buffer = Buffer.from(imageData, 'base64');

    // Save the image to a file
    fs.writeFile('received_image.jpg', buffer, (err) => {
      if (err) throw err;
      console.log('Image saved!');
    });

    res.writeHead(200, {'Content-Type': 'text/plain'});
    res.end('Image received');
  });
}
