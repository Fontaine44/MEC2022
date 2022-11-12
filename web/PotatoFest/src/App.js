import './App.css'
import '../node_modules/bootstrap/dist/css/bootstrap.min.css'
import ContactForm from './components/ContactForm'
import FAQ from './components/FAQ'
import Home from './components/Home'
import Tickets from './components/Tickets'
import Programmation from './components/Programmation'
import PracticalInfo from './components/PracticalInfo'
import Navbar from './components/Navbar'
import {Routes, Route} from "react-router-dom";

function App() {
  return (
    <div className="App">
      <Navbar />
    <Routes> 
        <Route path="/" element={<Home />} />
        <Route exact path="/tickets" element={<Tickets/>} />
        <Route exact path="/programmation" element={<Programmation/>} />
        <Route exact path="/practicalinfo" element={<PracticalInfo/>} />
        <Route exact path="/FAQ" element={<FAQ/>} />
        <Route exact path="/contactus" element={<ContactForm/>} />
    </Routes>
    
    </div>
  )
}
export default App