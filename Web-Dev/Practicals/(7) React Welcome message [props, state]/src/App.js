import React, { useState } from 'react';
import './App.css'; // Optional: for basic styling

function App() {
  return <DynamicWelcome defaultName="Guest" />;
}

function DynamicWelcome({ defaultName }) {
  const [currentName, setCurrentName] = useState(defaultName);
  const [inputValue, setInputValue] = useState('');

  const handleInputChange = (event) => {
    setInputValue(event.target.value);
  };

  const updateName = () => {
    if (inputValue.trim()) { // Only update if input is not empty/whitespace
        setCurrentName(inputValue);
    }
    setInputValue(''); // Clear input field
  };

  const resetName = () => {
    setCurrentName(defaultName);
    setInputValue('');
  };

  return (
    <div style={{ textAlign: 'center', marginTop: '50px' }}>
      <h1>Welcome, {currentName}!</h1>
      <input
        type="text"
        value={inputValue}
        onChange={handleInputChange}
        placeholder="Enter new name"
        style={{ marginRight: '10px', padding: '8px' }}
      />
      <button onClick={updateName} style={{ marginRight: '5px' }}>Update Name</button>
      <button onClick={resetName}>Reset Name</button>
    </div>
  );
}

export default App;
