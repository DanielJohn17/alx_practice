#!/usr/bin/node
import { createClient } from 'redis';

class RedisClient {
  constructor() {
    this.client = createClient();
    this.isClientConnected = true;

    this.client.on('error', (err) => {
      console.log(
        'Failed to connect to Redis client: ',
        err.message || err.toString(),
      );
      this.isClientConnected = false;
    });

    this.client.on('connect', () => {
      this.isClientConnected = true;
    });
  }

  isAlive() {
    return this.isClientConnected;
  }

  async get(key) {
    return new Promise((res, rej) => {
      this.client.GET(key, (error, result) => {
        if (error) {
          rej(error);
        } else {
          res(result);
        }
      });
    });
  }

  async set(key, value, duration) {
    return new Promise((res, rej) => {
      this.client.SETEX(key, duration, value, (err, reply) => {
        if (err) {
          rej(err);
        } else {
          res(reply);
        }
      });
    });
  }

  async del(key) {
    await new Promise((res, rej) => {
      this.client.DEL(key, (err, reply) => {
        if (err) {
          rej(err);
        } else {
          res(reply);
        }
      });
    });
  }
}

export const redisClient = new RedisClient();

export default redisClient;
