import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { databaseProviders } from './database.providers';

@Module({
  controllers: [AppController],
  providers: [AppService, ...databaseProviders],
})
export class AppModule {}
