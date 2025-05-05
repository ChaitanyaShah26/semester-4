import React from 'react';
import ProfileCard from './ProfileCard';
import './App.css';

const profileData = [
  {
    id: 1,
    avatar: '/images/profile1.jpeg',
    name: 'Hermione Granger',
    bio: 'Frontend Dev | React Fanatic',
    interests: ['Web Dev', 'UI/UX', 'Photography'],
    hobbies: ['Hiking', 'Sci-Fi', 'Baking'],
    skills: ['HTML', 'CSS', 'JS', 'React', 'Node.js', 'Figma'],
    initialLikes: 999
  },
  {
    id: 2,
    avatar: 'images/profile2.jpeg',
    name: 'Harry Potter',
    bio: 'Backend Engineer | Python/Django',
    interests: ['Distributed Systems', 'APIs', 'Databases'],
    hobbies: ['Guitar', 'Cooking', 'Travel'],
    skills: ['Python', 'Django', 'SQL', 'Docker', 'AWS', 'REST'],
    initialLikes: 421
  },
  {
    id: 3,
    avatar: 'images/profile3.jpeg',
    name: 'Luna Lovegood',
    bio: 'Data Scientist | ML Practitioner',
    interests: ['AI Ethics', 'NLP', 'Data Viz'],
    hobbies: ['Yoga', 'Painting', 'Board Games'],
    skills: ['Python', 'R', 'SQL', 'TensorFlow', 'Pandas', 'Tableau'],
    initialLikes: 260
  },
  {
    id: 4,
    avatar: 'images/profile4.jpeg',
    name: 'Draco Malfoy',
    bio: 'UX/UI Designer | Accessibility Advocate',
    interests: ['User Research', 'Interaction Design', 'Design Systems'],
    hobbies: ['Cycling', 'Sketching', 'Museums'],
    skills: ['Figma', 'Adobe XD', 'Wireframing', 'Prototyping', 'User Testing'],
    initialLikes: 680
  }
];

function App() {
  return (
    <div className="App">
      <h1 className="app-title">React Profile Showcase</h1>
      <div className="profile-container">
        {profileData.map((profile) => (
          <ProfileCard
            key={profile.id}
            avatar={profile.avatar}
            name={profile.name}
            bio={profile.bio}
            interests={profile.interests}
            hobbies={profile.hobbies}
            skills={profile.skills}
            initialLikes={profile.initialLikes}
          />
        ))}
      </div>
    </div>
  );
}

export default App;