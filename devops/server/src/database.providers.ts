import * as mongoose from 'mongoose';

export const databaseProviders = [
  {
    provide: 'DATABASE_CONNECTION',
    useFactory: (): any => {
      const databaseUrl = "mongo-db";
      mongoose.connect(`mongodb://root:root@${databaseUrl}:27017`);
    },
  },
];
