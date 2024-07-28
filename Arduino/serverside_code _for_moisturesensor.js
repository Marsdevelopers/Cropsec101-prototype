const http = require('http');

const server = http.createServer((req, res) => {
  if (req.url === '/moisture' && req.method === 'POST') {
    let body = '';

    req.on('data', chunk => {
      body += chunk.toString();
    });

    req.on('end', () => {
      try {
        const data = JSON.parse(body);
        const moisture = data.moisture;

        // Do something with the moisture data, e.g., log it to console
        console.log('Received moisture data:', moisture);

        res.writeHead(200, {'Content-Type': 'text/plain'});
        res.end('Moisture data received');
      } catch (error) {
        console.error('Error parsing JSON:', error);
        res.writeHead(400, {'Content-Type': 'text/plain'});
        res.end('Invalid JSON');
      }
    });
  } else {
    res.writeHead(404, {'Content-Type': 'text/plain'});
    res.end('Not found');
  }
});

server.listen(3000, () => {
  console.log('Server listening on port 3000');
});
