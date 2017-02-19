# Implementatieplan Scaling

<span style="font-style:italic;width:100%;display:block;"> Datum: 13 February 2017 </span>
<br />Made by: <br /><div style="margin-left: 20px">
Dimitry Volker | 1661152 <br >
Jasper van Hulst | 1660498
</div>

____________

Het op schaal brengen van een afbeelding is een belangrijk onderdeel van de pre-processing. Het is belangrijk dat alle invoerafbeeldingen, voor sommige programma’s, voordoen aan dezelfde criteria, denk hier over formaat, zwart-wit, edge detected, etc.


## 1. Doel
Voor het bewerken van een afbeelding is het belangrijk dat de afbeelding aan de alle invoerafbeeldingen voldoen aan dezelfde cirteria. In deze pre-processing fase zal er scaling uitgevoerd moeten worden.


## 2. Methoden
Voor het scalen van afbeeldingen zijn er veel methoden mogelijk. Hieronder staan ze beschreven met een korte uitleg over de werking en de verschillen tussen de methoden.

### 2.1 Nearest-Neighbor Interpolation
Nearest-Neighbor Interpolation is eigenlijk de simpelste manier van interpolatie. Er wordt gekeken naar de dichtsbijzijnde pixel (zijn neighbor) gekeken en daar wordt de intensiteit van overgenomen.
Als de scaling van de image 2 is, dan zal het net lijken of de pixels ook 2 keer zo groot zijn geworden.

![alt text](http://tech-algorithm.com/uploads/nneighbor01.png "Werking van Nearest Neighbour Image Scaling")

## 3. Keuze

