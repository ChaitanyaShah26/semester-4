import React from 'react';

function HomePage() {
  return (
    <div className="page-container home-page">
      <h1>Welcome to the React Concepts Demo!</h1>
      <p>This application demonstrates fundamental React concepts:</p>
      <ul>
        <li><strong>Routing:</strong> Navigate between Home, Items, and About pages.</li>
        <li><strong>Forms & Events:</strong> Add new items using the form on the Items page.</li>
        <li><strong>Keys:</strong> Used for efficiently rendering the list of items.</li>
        <li><strong>Refs:</strong> Used to automatically focus the input field on the Items page.</li>
      </ul>
      <p>Explore the different sections using the navigation bar above.</p>
    </div>
  );
}

export default HomePage;