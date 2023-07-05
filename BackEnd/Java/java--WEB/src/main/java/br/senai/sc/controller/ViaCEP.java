package br.senai.sc.controller;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import javax.json.Json;
import javax.json.JsonObject;
import javax.json.JsonReader;

public class ViaCEP {
    public static JsonObject getEndereco(String cep) {
        try {
            URL url = new URL("https://viacep.com.br/ws/" + cep + "/json/");
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("GET");
            connection.setRequestProperty("Accept", "application/json");

            if (connection.getResponseCode() == HttpURLConnection.HTTP_OK) {
                InputStreamReader inputStreamReader = new InputStreamReader(connection.getInputStream());
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

                JsonReader jsonReader = Json.createReader(bufferedReader);
                JsonObject jsonObject = jsonReader.readObject();
                jsonReader.close();

                return jsonObject;
            } else {
                System.out.println("Erro na requisição: " + connection.getResponseCode());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }
}
