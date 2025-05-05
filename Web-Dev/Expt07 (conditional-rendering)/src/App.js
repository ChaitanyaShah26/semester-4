import React, { useState } from 'react';
import './App.css';

function UserGreeting() {
  return (
    <div className="greeting user-greeting">
      <h2>Welcome back, Valued User!</h2>
      <p>Your dashboard is ready.</p>
    </div>
  );
}

function GuestGreeting() {
  return (
    <div className="greeting guest-greeting">
      <h2>Please Sign In</h2>
      <p>Access your account to continue.</p>
    </div>
  );
}

function LoginButton({ onClick }) {
  return (
    <button onClick={onClick} className="auth-button login-button">
      Log In
    </button>
  );
}

function LogoutButton({ onClick }) {
  return (
    <button onClick={onClick} className="auth-button logout-button">
      Log Out
    </button>
  );
}

function App() {
  const [isLoggedIn, setIsLoggedIn] = useState(false);
  const [showSecret, setShowSecret] = useState(false);

  const handleLoginClick = () => {
    setIsLoggedIn(true);
    setShowSecret(false);
  };

  const handleLogoutClick = () => {
    setIsLoggedIn(false);
    setShowSecret(false);
  };

  const toggleSecret = () => {
    setShowSecret(prevState => !prevState);
  }

  let button;
  if (isLoggedIn) {
    button = <LogoutButton onClick={handleLogoutClick} />;
  } else {
    button = <LoginButton onClick={handleLoginClick} />;
  }

  const numberOfMessages = 0;

  return (
    <div className="app-container">
      <header className="app-header">
        <h1>Conditional Rendering Showcase</h1>
      </header>

      <main className="main-content">
        <section className="status-section card">
          <h3>1. Ternary Operator</h3>
          {isLoggedIn ? <UserGreeting /> : <GuestGreeting />}
          {button}
        </section>

        <section className="logical-and-section card">
            <h3>2. Logical && Operator</h3>
            <p>This section only appears if logged in:</p>
            {isLoggedIn && (
                <div className="logged-in-content">
                    <p>You have unlocked premium content!</p>
                    <button onClick={toggleSecret} className="secret-toggle-button">
                        {showSecret ? 'Hide Secret' : 'Reveal Secret Message'}
                    </button>
                    {showSecret && <p className="secret-message">React is fun!</p>}
                </div>
            )}
            {!isLoggedIn && (
                 <p className="info-message">Log in to see the premium content and secret message toggle.</p>
            )}
        </section>

        <section className="inline-if-else-section card">
          <h3>3. Inline If-Else with Element Variables</h3>
           <p>The login/logout button above uses this technique (variable defined outside JSX).</p>
           <div className="info-message">
             Current Status: {isLoggedIn ? <strong>Logged In</strong> : <em>Logged Out</em>}
           </div>
        </section>

         <section className="null-render-section card">
            <h3>4. Preventing Render with `null` or `&&`</h3>
            <p>Example: Showing a message only if there are unread messages.</p>
            {numberOfMessages > 0 && (
                 <p className="warning-message">
                     You have {numberOfMessages} unread messages!
                </p>
            )}
            {numberOfMessages === 0 && (
                <p className="info-message">
                    You have no unread messages. (This component rendered because `numberOfMessages` is 0)
                </p>
            )}
         </section>
      </main>

      <footer className="app-footer">
        React Conditional Rendering Demo
      </footer>
    </div>
  );
}

export default App;