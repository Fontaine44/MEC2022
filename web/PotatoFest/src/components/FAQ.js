import Faq from "react-faq-component";
import {Link } from "react-router-dom";
const FAQ = () => {
const dataPPO = {
    title: "Permitted/prohibited objects",
    rows: [
        {
            title: "Will a swiss army knife get confiscated?",
            content: `Yes, no weapons are allowed on site.`,
        },
        {
            title: "Is this a marijuana friendly event?",
            content:
                "Marijuana is legal however there will be children around so be mindful of your surroundings.",
        },
        {
            title: "Are we allowed to bring reusable water bottles?",
            content: `Yes, but there will be concessions as well.  `,
        },
    ],
};
const dataAS = {
    title: "Access to the site",
    rows: [
        {
            title: "Does the site have wheelchair accessibility?",
            content: `The site is a park.`,
        },
        {
            title: "Is the site close to a metro station?",
            content:
                "Yes, the closest metro station is 5 minutes from the site.",
        },
        {
            title: "Is there an area to lock bikes?",
            content: `No, but there are a lot of trees.
            `,
        },
    ],
};
const dataSDT = {
    title: "Sale and delivery of tickets",
    rows: [
        {
            title: "Will I get an emial confirmation of my ticket and receipt?",
            content: `Yes.`,
        },
        {
            title: "Can I add the ticket to my apple pay?",
            content:
                "No.",
        },
        {
            title: "Can I pay with a visa gift card?",
            content: `No, only interact and credit cards. `,
        },
        {
            title: "My mom wont let me go anymore, is it possible to get refunded?",
            content: 'Sorry about your mom but no.',
        },
    ],
};

const styles = {
    // bgColor: 'white',
    titleTextColor: "blue",
    rowTitleColor: "blue",
    // rowContentColor: 'grey',
    // arrowColor: "red",
};

const config = {
    // animate: true,
    // arrowIcon: "V",
    // tabFocus: true
};

    return (
        <div>
            <h1>FAQ</h1>
            <Faq
                data={dataPPO}
                styles={styles}
                config={config}
            />
            <Faq
                data={dataAS}
                styles={styles}
                config={config}
            />
            <Faq
                data={dataSDT}
                styles={styles}
                config={config}
            />
            <li>
                <Link to="/contact">Contact</Link>
            </li>
        </div>
    );
}

export default FAQ