# Implementatieplan Scaling

<span style="font-style:italic;width:100%;display:block;"> Datum: 13 February 2017 </span>
<br />Made by: <br /><div style="margin-left: 20px">
Dimitry Volker | 1661152 <br >
Jasper van Hulst | 1660498
</div>

____________

Het op schaal brengen van een afbeelding is een belangrijk onderdeel van de pre-processing. Het is belangrijk dat alle invoerafbeeldingen, voor sommige programma’s, voordoen aan dezelfde criteria, denk hier over formaat, zwart-wit, edge detected, etc.


## 1. Doel
Voor het bewerken van een afbeelding is het belangrijk dat de afbeelding aan de alle invoerafbeeldingen voldoen aan dezelfde cirteria. In deze pre-processing fase zal er scaling uitgevoerd moeten worden. Voor het programma dient een afbeelding vergroot te worden (upscaling), maar ook verkleint worden (downscaling). Daarom moet de methode die geimplementeerd wordt, dit beide kunnen. 


## 2. Methoden
Wanneer we een bewerking uitvoeren op de afbeelding (transformatie) moet er voor iedere oude pixel in de afbeelding, een nieuwe pixel berekend worden in de nieuwe afbeelding. Hiervoor zijn er twee manieren: 

- Forward mapping
- Backward mapping

Tijdens deze implementatie wordt er vanuit gegaan van Backward mapping. Dit betekent dat de nieuwe pixel berekend wordt vanuit de oude afbeelding. Hierdoor zal elke pixel een kleur hebben. Er zijn diverse methoden om de kleur te bepalen van de nieuwe pixel. Uit alle methoden is er gekozen om er 3 te implementeren.


### 2.1 Nearest-Neighbor Interpolation
Nearest-Neighbor Interpolation is eigenlijk de simpelste manier van interpolatie. Er wordt gekeken naar de dichtsbijzijnde pixel (zijn neighbor) gekeken en daar wordt de intensiteit van overgenomen.
Als de scaling van de image 2 is, dan zal het net lijken of de pixels ook 2 keer zo groot zijn geworden.

![alt text](http://tech-algorithm.com/uploads/nneighbor01.png "Werking van Nearest Neighbour Image Scaling")

### 2.2 Bilinear Interpolation
Waar de Nearest-Neighbor Interpolation alleen kijkt naar de dichtsbijzijnde pixel en zijn waarde overneemt, kijkt de Bilinear manier naar de afstand van de 4 dichstbijzijnde pixels. 
Hoever de 4 pixels om de (nog uit te rekenen) pixel staat geeft aan hoeveel hun waardes wegen. 

![alt text](http://i.imgur.com/5Bctxml.png "Werking van Nearest Neighbour Image Scaling")

### 2.3 Bicubic Interpolation
Deze methode werkt hetzelfde als de Bilinear Interpolation. Het verschil zit hem echter in de hoeveelheid pixels er worden bekenen. Bij de Bilinear interplotie worden de pixels bekeken bij een 2x2 grid. Met de Bicubic wordt er gekeken naar een 4x4 grid. Totaal 16 pixels.

### 2.4 Honorable Mentions
De bovenstaande methoden zullen geimplementeerd worden, maar er zijn nog veel meer methoden. Deze staan hieronder beschreven met daarbij de reden waarom deze niet wordt meegenomen. 


#### 2.4.1 Sinc and Lancoz Resampling
Sinc resampling 


#### 2.4.2 Vectorizing 
Met deze methode worden wordt de afbeelding omgezet in (niet resolutie gebonden) vectors voor schaling. Het is een goede methode voor simpele geometrische afbeeldingen. Helaas zorgt deze methoden er veel voor dat er veel details verloren gaan (zie afbeelding hieronder)

![alt text](https://i.imgur.com/hiAKpCL.png "Werking van Nearest Neighbour Image Scaling")




#### 2.4.3 Mipmap

#### 2.4.4 Box Sampling



## 3. Implementatie

## 4. Evaluatie 

