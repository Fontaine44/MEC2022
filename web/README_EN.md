# Pre QEC 2023 - Web Design (10 points)

**NOTE**: There are similarities with the mobile challenge, but it is not 100% identical, pay attention.
## Scenario

The Potato Cloud Fest wants to entrust a team with the mandate of rebuilding their website *from scratch*! It is an important resource for anyone wanting to learn about the festival. We want a beautiful design that will convince those who are considering going to buy a ticket, and make those who already have theirs look forward to it.

You need to build a site to show them your web design skills.

## Required Software

There is no required software, you are free to use the technology you desire (for example Angular, React, Vue, ...).

You are only asked to do the *frontend* part, so you can *hardcode* your data directly in your code.

## Submission

1. You will need to demo your website to the judges (i.e. show them each detailed part below)
2. You must submit screenshots of your design
3. You must submit a copy of your source code

## Instructions
### **Homepage** (2 points)

The homepage should contain:
- The dates of the festival (26-27 January 2023)
- Location of the festival (Montreal)
- The logo of the festival (your pick)
- A menu with these different options:
    - Tickets
    - Programmation
    - Practical info
    - FAQ
    - Contact Us
- A countdown to the start of the event (January 26, 2023)

### **Ticketing page** (2 points)
This page is meant to show users the different ticket options for the event and allow them to add tickets to a shopping cart. You should not implement the section to complete the purchase.

The available ticket types are in `tickets.json`.

The pricing page should contain:
- The list of different tickets and bundles that can be purchased (`tickets.json`). For each option:
     - Name
     - Price
     - Description
     - Button to add to cart
- Shopping cart that contains the added items

### **Programming oage** (3 points)

This page allows site visitors to view the full schedule.

The events that will make up the schedule are given in `schedule.csv`. You can *parse* the data as you want (if you feel like copying by hand you can too).

(*NOTE: The first line of the CSV represents the column names, the rest is the data.*)
The programming page must contain:
- A schedule(s) that show the festival schedule (`schedule.csv`). You choose how to organize the data (by date, place, type, etc.)
- Every event in `schedule.csv`, integrated with grid
     - Name
     - Date and time
     - Venue
     - Type
- When clicking on an event in the grid, a way of visualizing (section that *expands*, dialog, popup, popover, etc)
     - Name, date, time, location, type
     - Brief description (you can invent it or put a placeholder, you won't be graded on it)
### **FAQ Page** (2 points)
The FAQ page, as the name suggests, is for answering user questions. The design must allow you to quickly find a question and access its answer.

The FAQ page should contain:
- Minimum 10 questions (total) separated into 3 sections
     - For example, sections:
         - Permitted/prohibited objects
         - Access to the site
         - Sale and delivery of tickets
- A link to the Contact Us page

You can invent the questions, answers and sections. You will not be graded on the content.

### **Contact Us page** (1 point)

The Contact Us page should show site visitors the various options for contacting the festival's organizing committee.

The Contact Us page should contain:
- Contact details of the organizers
     - Telephone
     - Address
     - Email Address
- Section to send a message
     - Input for name
     - Input for email
     - Input for telephone
     - Input for message
     - Send button (not functional)