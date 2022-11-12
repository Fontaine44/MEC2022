import { HttpClient, HttpErrorResponse } from '@angular/common/http';
import { Component } from '@angular/core';
import { catchError, Observable, throwError } from 'rxjs';


interface Healthcheck {
  alive: boolean
}

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'Pré-CQI 2023';
  serverBaseUrl = 'http://localhost:3000'
  mongoOk = false;
  serverOk = false;

  constructor(private readonly _httpClient: HttpClient) { }

  ngOnInit(): void {
    this._httpClient.get<Healthcheck>(`${this.serverBaseUrl}/healthcheck`)
      .pipe(catchError(this.handleServerError))
      .subscribe((response: Healthcheck) => {
        this.serverOk = response.alive;
      });

    this._httpClient.get<boolean>(`${this.serverBaseUrl}/mongo`)
      .pipe(catchError(this.handleMongoError))
      .subscribe((response: boolean) => {
        this.mongoOk = response;
      });
  }

  private handleServerError(error: HttpErrorResponse): Observable<never> {
    this.serverOk = false;

    if (error.status === 0) {
      // A client-side or network error occurred. Handle it accordingly.
      console.error('An error occurred:', error.error);
    } else {
      // The backend returned an unsuccessful response code.
      // The response body may contain clues as to what went wrong.

      console.error(
        `Backend returned code ${error.status}, body was: `, error.error);
    }
    return throwError(() => new Error('Something bad happened; please try again later.'));
  }

  private handleMongoError(error: HttpErrorResponse): Observable<never> {
    this.mongoOk = false;

    if (error.status === 0) {
      // A client-side or network error occurred. Handle it accordingly.
      console.error('An error occurred:', error.error);
    } else {
      // The backend returned an unsuccessful response code.
      // The response body may contain clues as to what went wrong.

      console.error(
        `Backend returned code ${error.status}, body was: `, error.error);
    }
    return throwError(() => new Error('Something bad happened; please try again later.'));
  }
}
