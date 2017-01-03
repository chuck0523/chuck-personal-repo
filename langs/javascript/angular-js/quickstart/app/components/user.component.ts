import { Component } from '@angular/core';

@Component({
    selector: 'user',
    template: `
    <h1>{{name}}</h1>
    <p> <strong>Email: </strong> {{email}} </p>
    <p> <strong>Address: </strong> {{ address.street }} {{ address.city }} {{ address.country }} </p>
    <button (click)="toggleHobbies()">{{ showHobbies ? "Hide" : "Show"}} Hobbies</button>
    <div *ngIf="showHobbies">
        <h3>Hobbies</h3>
        <ul>
            <li *ngFor="let hobby of hobbies; let i = index">
                {{ hobby }} <button (click)="deleteHobby(i)">X</button>
            </li>
        </ul>
        <form (submit)="addHobby(hobby.value)">
            <label>Add hobby: </label><br />
            <input type="text" #hobby /><br />
        </form>
    </div>
    <hr />
    <h3>Edit User</h3>
    <form>
        <label>Name: </label><br />
        <input type="text" name="name" [(ngModel)]="name" /><br />
        <label>Email: </label><br />
        <input type="text" name="email" [(ngModel)]="email" /><br />
        <label>Street: </label><br />
        <input type="text" name="address.street" [(ngModel)]="address.street" /><br />
    </form>
  `,
})
export class UserComponent  {
    name: string;
    email: string;
    address: address;
    hobbies: string[];
    showHobbies: boolean;

    constructor() {
        this.name = 'Sam Smith'
        this.email = 'chuck@gmail.com'
        this.address = {
            street: "hoge 12 st",
            city: "Tokyo",
            country: "Japan",
        }
        this.hobbies = ['Music', 'Movies', 'Sports'];
        this.showHobbies = false;
    }
    toggleHobbies() {
        this.showHobbies = !this.showHobbies
    }
    addHobby(hobby: string) {
        this.hobbies.push(hobby)
    }
    deleteHobby(i: number) {
        this.hobbies.splice(i, 1)
    }
}
interface address {
    street: string,
    city: string,
    country: string,
}
