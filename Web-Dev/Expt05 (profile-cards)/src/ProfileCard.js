import React, { useState } from 'react';
import './ProfileCard.css';

function ProfileCard(props) {
  const {
    avatar,
    name,
    bio,
    interests,
    hobbies,
    skills,
    initialLikes
  } = props;

  const [likes, setLikes] = useState(initialLikes);
  const [isLiked, setIsLiked] = useState(false); 
  const [isConnected, setIsConnected] = useState(false);

  const handleLikeClick = () => {
    if (isLiked) {
      setLikes(likes - 1);
      setIsLiked(false);
    } else {
      setLikes(likes + 1);
      setIsLiked(true);
    }
    console.log(`${name} like status: ${!isLiked}, New count: ${isLiked ? likes - 1 : likes + 1}`);
  };

  const handleConnectClick = () => {
      setIsConnected(!isConnected);
      alert(`You are now ${!isConnected ? 'connected with' : 'disconnected from'} ${name}!`);
      console.log(`Connect button clicked for ${name}! Status: ${!isConnected ? 'Connected' : 'Disconnected'}`);
  };

  const renderList = (items, listClassName) => (
    <ul className={listClassName}>
      {items.map((item, index) => (
        <li key={index}>{item}</li>
      ))}
    </ul>
  );

  return (
    <div className="profile-card">
      <div className="profile-header">
        <img src={avatar} alt={`${name}'s avatar`} className="profile-avatar" />
        <h2 className="profile-name">{name}</h2>
        <p className="profile-bio">{bio}</p>
      </div>

      <div className="profile-details">
        {/* Conditionally render sections only if data exists */}
        {interests && interests.length > 0 && (
            <div className="detail-section">
            <h3>Interests</h3>
            {renderList(interests, 'interests-list tag-list')}
            </div>
        )}
        {hobbies && hobbies.length > 0 && (
            <div className="detail-section">
            <h3>Hobbies</h3>
            {renderList(hobbies, 'hobbies-list tag-list')}
            </div>
        )}
         {skills && skills.length > 0 && (
            <div className="detail-section skills-section">
            <h3>Skills</h3>
            {renderList(skills, 'skills-list tag-list')}
            </div>
         )}
      </div>

      <div className="profile-actions">
        <button
            className={`btn connect-btn ${isConnected ? 'connected' : ''}`}
            onClick={handleConnectClick}
        >
           {isConnected ? 'Connected ✓' : 'Connect'}
        </button>
        <div className="like-section">
          { }
          <button
            className={`btn like-btn ${isLiked ? 'liked' : ''}`}
            onClick={handleLikeClick}
            // Update aria-label based on state
            aria-label={isLiked ? 'Unlike profile' : 'Like profile'}
          >
            {/* Use span for potential icon font/SVG later if needed */}
            <span role="img" aria-hidden="true">❤️</span>
          </button>
          <span className="like-count">{likes}</span>
        </div>
      </div>
    </div>
  );
}

export default ProfileCard;