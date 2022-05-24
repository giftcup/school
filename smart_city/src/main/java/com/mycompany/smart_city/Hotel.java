/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.smart_city;

/**
 *
 * @author pro-3is
 */
public class Hotel {

    public String hotel_name;
    public int hotel_price;
    public String town;
    public int evaluation = 0;
    public int recommendation;

    @Override
    public String toString() {
        return "\n Hotel name: " + this.hotel_name
                + "\n Town: " + this.town
                + "\n Evaluation: " + this.evaluation
                + "\n Recommendation: " + this.recommendation;
    }

    void increment_evaluation() {
        if (this.recommendation > 100) {
            while (evaluation < 5) {
                this.evaluation = this.recommendation / 100;
            }
        }
    }

    void increment_recommendation() {
        this.recommendation++;
    }

    Hotel(String name, int price, int evaluation, String town) {
        this.hotel_name = name;
        this.hotel_price = price;
        this.evaluation = evaluation;
        this.town = town;
    }

}
