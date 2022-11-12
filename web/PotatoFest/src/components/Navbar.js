import React from "react";
import {Link } from "react-router-dom";

function Navbar() {
  return (
      <ul>
        <li>
          <Link to="/tickets">Tickets</Link>
        </li>
        <li>
          <Link to="/programmation">Programmation</Link>
        </li>
        <li>
          <Link to="/practicalinfo">Practical Info</Link>
        </li>
        <li>
          <Link to="/FAQ">FAQ</Link>
        </li>
        <li>
          <Link to="/contactus">Contact</Link>
        </li>
      </ul>
  );
}

export default Navbar;
