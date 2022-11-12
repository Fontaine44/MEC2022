import { Injectable, Scope } from '@nestjs/common';
import * as mongoose from 'mongoose';
import { ConnectionStates } from 'mongoose';
@Injectable({ scope: Scope.REQUEST })
export class AppService {
  getHello(): string {
    return 'Pré-CQI 2023';
  }

  testServerConnection(): { alive: boolean } {
    return { alive: true };
  }

  testMongoConnection(): ConnectionStates {
    return mongoose.connection.readyState;
  }
}
