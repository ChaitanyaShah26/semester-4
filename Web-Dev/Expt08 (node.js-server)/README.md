# Node.js Server

Before you begin, ensure you have the following installed on your system:

1.  **Node.js and npm:** Required for both the React application and the Node.js server. Download and install from [nodejs.org](https://nodejs.org/).
    *   You can verify installation by opening your terminal or command prompt and running:
        ```bash
        node -v
        npm -v
        ```

## 
This application is a basic Node.js server that serves static files from a `public` directory.

**Steps:**

1.  **Navigate to the Project Directory:**
   
2.  **Run the Server:**
    Execute the server script using Node.js:
    ```bash
    node server.js
    ```
    *   You should see confirmation in the terminal that the server has started, usually like:
        ```
        Server started on http://localhost:3000
        ```
    
4.  **Access Served Content:**
    *   Open your web browser and navigate to `http://localhost:3000`
    *   You should see the content of your `public/index.html` file.

5.  **Stop the Server:**
    To stop the Node.js server, go back to the terminal where it's running and press `Ctrl + C`.