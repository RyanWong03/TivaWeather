import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [temperature, setTemperature] = useState(null);

  const fetchTemperature = () => {
    fetch('http://127.0.0.1:5000/api/temperature')
      .then((response) => response.json())
      .then((data) => setTemperature(data.temperature))
      .catch((error) => console.error('Error fetching temperature:', error));
  };

  const turnOnFan = () => {
    // Send a POST request to Flask server
    fetch('http://127.0.0.1:5000/api/turnOnFan', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',  // Send JSON data
      },
      body: JSON.stringify({ status: 'on' })  // Send status to backend
    })
      .then((response) => {
        if (response.ok) {
          console.log('Fan turned on successfully');
        } else {
          console.error('Error turning on fan');
        }
      })
      .catch((error) => console.error('Error:', error));
  };
  

  return (
    <div>
      <h1>Room Temp Viewer 🌡️</h1>
      <button onClick={fetchTemperature}>View Temperature</button>
      {temperature !== null && (
        <p>Current temperature: {temperature}°C</p>
      )}
      
      <br></br>
      <br></br>
      
      <button onClick={turnOnFan}>Turn on Fan</button>
    </div>
  );
}

export default App;
