import React from 'react';

function AboutPage() {
  return (
    <div className="page-container about-page">
      <h2>About This Application</h2>
      <p>
        This application was created to provide a clear, practical demonstration
        of several core React concepts within a single project.
      </p>
      <p>Concepts Illustrated:</p>
      <ul>
        <li><strong>React Router DOM:</strong> For client-side routing (v6 syntax).</li>
        <li><strong>Controlled Components:</strong> The form input is controlled by React state.</li>
        <li><strong>Event Handling:</strong> `onChange`, `onSubmit`, and `onClick` handlers manage user interactions.</li>
        <li><strong>`useState` Hook:</strong> For managing component state (input value, list of items).</li>
        <li><strong>`useRef` Hook:</strong> To directly access the input DOM element for focusing.</li>
        <li><strong>`useEffect` Hook:</strong> To perform side effects (focusing the input on mount).</li>
        <li><strong>List Rendering with Keys:</strong> Mapping over the items array and providing unique `key` props for performance and identity.</li>
      </ul>
      <p>
        The styling is done using plain CSS in `App.css` to keep it simple while aiming for an attractive look.
      </p>
    </div>
  );
}

export default AboutPage;