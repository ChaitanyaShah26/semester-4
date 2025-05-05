const http = require('http');
const fs = require('fs');
const path = require('path');

const PORT = 3000;
const PUBLIC_DIRECTORY = path.join(__dirname, 'public'); // Content served from './public' folder

const mimeTypes = {
    '.html': 'text/html',
    '.css': 'text/css',
    '.js': 'application/javascript',
    '.png': 'image/png',
    '.jpg': 'image/jpeg',
    '.jpeg': 'image/jpeg',
    '.gif': 'image/gif',
    '.svg': 'image/svg+xml',
    '.ico': 'image/x-icon'
};

const server = http.createServer((req, res) => {
    // Determine the file path from the URL
    let filePath = path.join(PUBLIC_DIRECTORY, req.url === '/' ? 'index.html' : req.url);

    // Sanitize file path to prevent directory traversal
    const safeFilePath = path.normalize(filePath);
    if (!safeFilePath.startsWith(PUBLIC_DIRECTORY)) {
        console.warn(`Forbidden request: ${req.url}`);
        res.writeHead(403, { 'Content-Type': 'text/plain' });
        res.end('403 Forbidden');
        return;
    }

    // Check if the file exists
    fs.access(safeFilePath, fs.constants.R_OK, (err) => {
        if (err) {
            console.log(`File not found: ${safeFilePath}`);
            res.writeHead(404, { 'Content-Type': 'text/plain' });
            res.end('404 Not Found');
            return;
        }

        // Determine the Content-Type based on file extension
        const ext = path.extname(safeFilePath).toLowerCase();
        const contentType = mimeTypes[ext] || 'application/octet-stream'; // Default type

        // Read the file and serve it
        fs.readFile(safeFilePath, (error, content) => {
            if (error) {
                console.error(`Error reading file: ${safeFilePath}`, error);
                res.writeHead(500, { 'Content-Type': 'text/plain' });
                res.end('500 Internal Server Error');
            } else {
                console.log(`Serving: ${req.url} -> ${safeFilePath}`);
                res.writeHead(200, { 'Content-Type': contentType });
                res.end(content, 'utf-8');
            }
        });
    });
});

server.listen(PORT, () => {
    console.log(`Server started on http://localhost:${PORT}`);
    console.log(`Serving static files from: ${PUBLIC_DIRECTORY}`);
});

// Basic error handling for the server itself
server.on('error', (err) => {
    console.error('Server error:', err);
});