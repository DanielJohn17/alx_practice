#!/usr/bin/node
import express from 'express';
import injectRoutes from './routes';

const server = express();
const port = process.env.PORT || 5000;

server.use(express.json());

injectRoutes(server);

server.listen(port, () => {
  console.log(`Server app is litsening on port ${port}`);
});
