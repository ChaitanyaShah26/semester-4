import React, { useState, useRef, useEffect } from 'react';

function ItemsPage() {
  const [items, setItems] = useState([
    { id: 1, text: 'Learn React Basics' },
    { id: 2, text: 'Practice Routing' },
  ]);
  const [inputValue, setInputValue] = useState('');
  const inputRef = useRef(null);

  useEffect(() => {
    if (inputRef.current) {
      inputRef.current.focus();
    }
  }, []);

  const handleInputChange = (event) => {
    setInputValue(event.target.value);
  };

  const handleSubmit = (event) => {
    event.preventDefault();
    if (!inputValue.trim()) return;

    const newItem = {
      id: Date.now(),
      text: inputValue.trim()
    };

    setItems(prevItems => [...prevItems, newItem]);
    setInputValue('');
    if (inputRef.current) {
        inputRef.current.focus();
    }
  };

  const handleDeleteItem = (idToDelete) => {
    setItems(prevItems => prevItems.filter(item => item.id !== idToDelete));
     if (inputRef.current) {
        inputRef.current.focus();
    }
  };

  return (
    <div className="page-container items-page">
      <h2>Manage Your Items</h2>

      <form onSubmit={handleSubmit} className="item-form">
        <input
          ref={inputRef}
          type="text"
          value={inputValue}
          onChange={handleInputChange}
          placeholder="Add a new item..."
          className="item-input"
        />
        <button type="submit" className="add-button">Add Item</button>
      </form>

      <h3>Item List</h3>
      {items.length === 0 ? (
        <p className="empty-list-message">No items yet. Add some above!</p>
      ) : (
        <ul className="item-list">
          {items.map((item) => (
            <li key={item.id} className="list-item">
              <span>{item.text}</span>
              <button
                onClick={() => handleDeleteItem(item.id)}
                className="delete-button"
              >
                Remove
              </button>
            </li>
          ))}
        </ul>
      )}
    </div>
  );
}

export default ItemsPage;