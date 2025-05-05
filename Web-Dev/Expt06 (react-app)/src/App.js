import React from 'react';
import { Routes, Route } from 'react-router-dom';
import Navigation from './components/Navigation';
import HomePage from './components/HomePage';
import ItemsPage from './components/ItemsPage';
import AboutPage from './components/AboutPage';
import './App.css';

function App() {
  return (
    <div className="App">
      <Navigation />
      <main className="content">
        <Routes>
          <Route path="/" element={<HomePage />} />
          <Route path="/items" element={<ItemsPage />} />
          <Route path="/about" element={<AboutPage />} />
        </Routes>
      </main>
    </div>
  );
}

export default App;