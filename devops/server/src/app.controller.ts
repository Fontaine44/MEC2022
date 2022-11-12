import { Controller, Get } from '@nestjs/common';
import { AppService } from './app.service';

@Controller()
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get()
  getHello(): string {
    return this.appService.getHello();
  }

  @Get('healthcheck')
  testServerConnection(): { alive: boolean } {
    return this.appService.testServerConnection();
  }

  @Get('mongo')
  testMongoConnection(): boolean {
    return this.appService.testMongoConnection() == 1;
  }
}
