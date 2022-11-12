# Pre-QEC 2023 - Mobile Design (10 points)

 **NOTE**: There are similarities with the web challenge, but it's not 100% identical, pay attention.
 
## Scenario

The Potato Cloud Fest wants to know if you are the right team to build an app that will improve the experience of its festival-goers! It's a platform where customers can create an account, view event info, build a schedule of what they want to attend, and more.

So you create a *lite* version of the app to show them your mobile *skills*.

## Required Software
There is no required software for this competition, but you must develop the application with a native SDK, so iOS or Android (no React Native or equivalent).

You must be able to do a demo at the end (on a simulator or a phone).

You are only asked to do the *frontend* part, so you can *hardcode* your data directly in your code.

## Submission
1. You will need to demo your application to the judges (i.e. show them each detailed part below)
2. You must submit screenshots of your design
3. You must submit a copy of your source code

## Instructions
### **Authentication** (2 points)

The authentication page must at least contain:
- The festival logo (at your discretion!)
- Input for email
- Input for the password (minimum 10 characters)
- Links or buttons to (do not have to be functional)
     - Create an account
     - Forgot your password

### **Homepage** (2 points)

The homepage should contain:
- The dates of the festival (26-27 January 2023)
- Location of the festival (Montreal)
- The logo of the festival
- A navbar with the different menu options:
     - Personal information
     - Programming
     - Custom schedule
     - Practical information
     - Contact us
- A countdown to the start of the event (January 26, 2023)

### **Personal information page** (2 points)

This page allows festival-goers to enter their information and preferences. This info can then be used to manage emergencies, lost items, contests, etc.

The personal information page should contain:
- Section allowing the modification of confidential information
     - New Password
     - Confirmation of the new password
     - Old Password
- Section allowing the modification of the contact information
     - Address
     - Address (continued)
     - Town
     - Province
     - Country
     - Postal code
     - Telephone
- Section allowing the modification of an emergency contact
     - Last name
     - First name
     - Telephone
     - Relationship with the person
- Section allowing the modification of health information
     - Allergies/intolerances
     - Known health issues
     - Medications
- Section allowing the modification of preferences
     - Frequency of promo emails
        - Never, 1/month, 1/week, 1/day 
    - Tshirt size
- Save button

### **Custom schedule page** (4 points)

This page allows participants to consult the schedule that they will have built from the complete programming. In other words, imagine the user can view the entire schedule and select events to create a reminder of where to go, when. You *don't* have to do the scheduling part, just display the custom schedule.

The events that will make up the schedule are given in `schedule.csv`. You can *parse* the data as you want (if you feel like copying by hand you can too).

(*NOTE: The first line of the CSV represents the column names, the rest is the data.*)

The custom schedule page should contain:
- A schedule grid of festival dates (January 26-27)
- Events chosen by the user in the grid
     - Event name
     - Date and time
     - Venue
     - Type
- When you tap on an event in the grid, a popup containing
     - Name, date, time, location, type
     - Brief description (you can invent it or put a placeholder, you won't be graded on it)