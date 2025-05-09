import React, { useState } from 'react';
import './App.css'; // Optional: for basic styling if needed

function App() {
  return <WelcomeMessage userName="Student" />;
}

function WelcomeMessage({ userName }) {
  const [isLoggedIn, setIsLoggedIn] = useState(false); // Start logged out

  const toggleLogin = () => {
    setIsLoggedIn(!isLoggedIn); // Flip the state
  };

  return (
    <div style={{ textAlign: 'center', marginTop: '50px' }}>
      <h1>
        {isLoggedIn ? `Welcome, ${userName}!` : 'Please log in'}
      </h1>
      <button onClick={toggleLogin}>
        {isLoggedIn ? 'Log Out' : 'Log In'}
      </button>
    </div>
  );
}

export default App;
