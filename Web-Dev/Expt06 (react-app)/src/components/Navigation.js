import React from 'react';
import { NavLink } from 'react-router-dom';

function Navigation() {
  return (
    <nav className="navbar">
      <div className="nav-brand">React Concepts</div>
      <ul className="nav-links">
        <li><NavLink to="/" className={({ isActive }) => isActive ? "nav-link active" : "nav-link"}>Home</NavLink></li>
        <li><NavLink to="/items" className={({ isActive }) => isActive ? "nav-link active" : "nav-link"}>Items</NavLink></li>
        <li><NavLink to="/about" className={({ isActive }) => isActive ? "nav-link active" : "nav-link"}>About</NavLink></li>
      </ul>
    </nav>
  );
}

export default Navigation;