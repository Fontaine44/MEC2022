# Pre CQI 2023 - DevOps (10 points)

## Context

The DevOps challenge serves to evaluate your competencies about the usage od Docker and DevOps concepts.

## Installing Docker

Install the “Community Edition” (CE) version
https://docs.docker.com/v17.12/install/

## Delivery

1. Delete your (2) `node_modules` folders.
2. Create an archive containing your `client`, `server` folders, your `docker-compose.yml`.
3. Upload the archive to the exam form.

## Practical questions

*Note that both client and server use the `yarn` package manager.*

### Q1 (3 points)

Under the `server` folder, you will find a simple JS REST server.

Complete `server/Dockerfile.prod` in multi-stage with a build stage and an execution stage.

You will need to be able to make the following REST call on your dockerized server:

```
GET /healthcheck
```

### Q2 (3 points)

Under the `client` folder, you will find an Angular app.

Complete `client/Dockerfile.prod` in multi-stage with one build step and one runtime.

You will need to be able to access the home page from your browser.

### Q3 (2 points)

Complete the `docker-compose.yml` to create an environment where a client can communicate with the server.

To verify the connection, you can rely on the *Server is connected* message displayed when refreshing the client's home page.

Modify the `serverBaseUrl` variable of `client/src/app/app.component.ts` as needed to ensure the connection.

### Q4 (2 points)

Add to `docker-compose.yml` a mongoDB instance so that the server can access it.

To verify the connection, you can make the following REST call to the server:
```
GET /mongo
```
or you can rely on the message *Mongo is connected* displayed when refreshing the client's home page.


Modify the `databaseUrl` variable of `server/src/database.provider.ts` as needed to ensure the connection.