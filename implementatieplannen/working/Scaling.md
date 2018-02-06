# Implementatieplan Scaling

<span style="font-style:italic;width:100%;display:block;"> Datum: 3 November 2017 </span>
<br />Made by: <br /><div style="margin-left: 20px">
Dimitry Volker | 1661152 <br >
Jasper van Hulst | 1660498
</div>

____________

Het op schaal brengen van een afbeelding is een belangrijk onderdeel van de pre-processing. Het is belangrijk dat alle invoerafbeeldingen, voor sommige programma’s, voordoen aan dezelfde criteria, denk hier over formaat, zwart-wit, edge detected, etc.

## 1. Doel
Voor het bewerken van een afbeelding is het belangrijk dat de afbeelding aan de alle invoerafbeeldingen voldoen aan dezelfde cirteria. In deze pre-processing fase zal er scaling uitgevoerd moeten worden. Voor het programma dient een afbeelding vergroot te worden (upscaling), maar ook verkleint worden (downscaling). Daarom moet de methode die geimplementeerd wordt, dit beide kunnen. Echter zijn er drie belangrijke factoren waarop een algoritme gekozen kan worden voor scaling.

- Snelheid
- Kwaliteit van de Afbeelding
- Integratie met Arno's algoritme

## 2. Methoden

### 2.1 Mapping

Wanneer we een bewerking uitvoeren op de afbeelding (transformatie) moet er voor iedere oude pixel in de afbeelding, een nieuwe pixel berekend worden in de nieuwe afbeelding. Hiervoor zijn er twee manieren: 

- Forward mapping
- Backward mapping

#### 2.1.1 Forward Mapping
Wanneer er een transformatie word gedaan op een afbeelding, word er vaak meteen gedacht aan de oude pixel naar de nieuwe afbeelding te plaatsen. Eerst bereken je waar deze ongeveer moet komen en welke kleur deze moet hebben. 

Echter is het mogelijk dat de oude afbeelding minder pixels bevat dan de nieuwe. Hierdoor kan er nooit gegarandeerd worden dat alle pixels een kleur krijgen in de nieuwe afbeelding. Dus hoe groter de afbeelding hoe groter de gaten worden waar geen "kleur" is.

Het voordeel van Foward Mapping is dat dit snel is aangezien er weinige uitgerekend hoeft te worden. Je zou dit eventueel kunnen gebruiken wanneer je "use case" bijvoorbeeld is dat een afbeelding alleen kleiner gemaakt moet worden. 

#### 2.1.2 Backward Mapping
Om het probleem te tackelen van Forward mapping is er nog Backward Mapping.  Dit maakt gebruik van de inverse tranformatie van Forward Mapping. Hierdoor krijgen alle pixels in de nieuwe afbeelding een kleur. Echter kan dit er wel voor zorgen dat de kleuren (of details) wegvallen vanwege de berekening voor een nieuwe kleur. Er zijn verschillende manieren om de nieuwe kleur te berekenen, de methoden staan verder in dit hoofdstuk beschreven. 


#### 2.1.3 Gebruikte mapping methode
Tijdens deze implementatie wordt er vanuit gegaan van Backward mapping. Dit betekent dat de nieuwe pixel berekend wordt vanuit de oude afbeelding. Hierdoor zal elke pixel een kleur hebben. Er zijn diverse methoden om de kleur te bepalen van de nieuwe pixel. Uit alle methoden is er gekozen om er 3 te implementeren.


### 2.1 Nearest-Neighbor Interpolation
![ImageScaling text | center](http://tech-algorithm.com/uploads/nneighbor01.png "Werking van Nearest Neighbour Image Scaling")

Nearest-Neighbor Interpolation is eigenlijk de simpelste manier van interpolatie. Vanaf de nieuw afbeelding word er gekeken waar de pixel ongeveer moet zijn op de oude afbeelding. Hier word er gekeken naar de dichtsbijzijnste pixel van de berekende locatie en dan word de intensiteit van die pixel overgenomen. 

Het nadeel van deze methode is dat er aliasing op treed aan de randen. Hierdoor kunnen gradients niet makkelijk vergroot worden en zullen de randen er ook kartelig uit zien. Zoals hieronder ook gedemonstreed is. 


![Aliasing test | center](http://i.imgur.com/BRyg26q.png "Aliasing die optreed bij vergroten.")



### 2.2 Bilinear Interpolation
![alt text](http://i.imgur.com/5Bctxml.png "Werking van Nearest Neighbour Image Scaling")

Waar de Nearest-Neighbor Interpolation alleen kijkt naar de dichtsbijzijnde pixel en zijn waarde overneemt, kijkt de Bilinear manier naar de afstand van de 4 dichstbijzijnde pixels.  

De afstand word gebruikt voor de weging van zijn intensiteit (Die altijd optellen naar 1 totaal). Uiteindelijk worden alle kleuren bij elkaar opgeteld gebaseerd op de weginging en word daar het gemiddelde uit gehaald. 

Hierdoor krijg je een evenwichtiger effect wanneer je een afbeelding vergoot. Er onstaat en wat normalere overgang en het gaat kartel randen tegen (aliasing).

![alt text](https://i.imgur.com/y6RGjPn.png "Vergroten met Bilinear Interpolatie").



### 2.3 Bicubic Interpolation
![alt text](https://wiki.blender.org/uploads/c/c6/Bicubic_scale_node.gif "Grid van Bicubic Interpolatie")

Deze methode werkt hetzelfde als de Bilinear Interpolation. Het verschil zit hem echter in de hoeveelheid pixels er worden bekenen. Bij de Bilinear interplotie worden de pixels bekeken bij een 2x2 grid. Met de Bicubic wordt er gekeken naar een 4x4 grid. Totaal 16 pixels.

Hierdoor onstaan er  evenwichtere overgangen dan bij bilinear maar, het kost ook meer tijd om de nieuwe afbeelding te maken.

### 2.5 Honorable Mentions
De bovenstaande methoden zullen geimplementeerd worden, maar er zijn nog veel meer methoden. Deze staan hieronder beschreven met daarbij de reden waarom deze niet wordt meegenomen. 

#### 2.5.2 Vectorizing 
Met deze methode worden wordt de afbeelding omgezet in (niet resolutie gebonden) vectors voor schaling. Het is een goede methode voor simpele geometrische afbeeldingen. Helaas zorgt deze methoden er veel voor dat er veel details verloren gaan (zie afbeelding hieronder).

![alt text](https://i.imgur.com/hiAKpCL.png "Werking van Nearest Neighbour Image Scaling")

Deze methode werkt goed voor simpele geometrische vormen maar niet goed voor foto's. Vanwege deze reden hebben we er voor gekozen om deze niet te implementeren. 

#### 2.5.3 Box Sampling
Een van de zwakte van de bovenstaanden methodes is dat wanneer je een afbeelding kleiner maakt onder een bepaalde drempelwaarde, zullen de methoden niet aangrenzende pixels meenemen in de calculatie waardoor je veel data verlies krijgt.

De eventuele oplossing hiervoor zou zijn dat je altijd een soort "doosbemonstering" uitvoert. Hierdoor kies je een bepaald gebied van de afbeelding waar je alle waardes van de pixels meetelt.

Waarom nemen wij deze niet mee in ons practica? Het is namelijk erg moeilijk om een goed resultaat te krijgen. Er zijn veel randwaarden zoals, hoe groot is het gebied wat ik sample? Heeft alles dezelfde weging of maak ik daar onderscheid in? etc. 

## 3. Implementatie

### 3.1 Nearest-Neighbor Interpolation
```C++
While next vericle pixel not last pixel
	While next horizontal pixel not last pixel
		set near vericle pixel = vericle pixel * source pixsel / size destination
		set near horizontal pixel = horizontal pixel * source pixsel / size destination

		pixel vericle and horizontal = source near vericle pixel and near horizontal pixel
	endWhile
endWhile
```

### 3.2 Bilinear Interpolation
```C++
While next vericle pixel not last pixel
	While next horizontal pixel not last pixel

		set near vericle pixel = vericle pixel * source pixsel / size destination
		set near horizontal pixel = horizontal pixel * source pixsel / size destination

		pixel 1 = 1 pixel up near vericle pixel and near horizontal pixel
		pixel 2 = 1 pixel left near vericle pixel and near horizontal pixel
		pixel 3 = 1 pixel right near vericle pixel and near horizontal pixel
		pixel 4 = 1 pixel down near vericle pixel and near horizontal pixel

		pixel prox 1 = lijn tussen pixel 1 en pixel 2
		pixel prox 2 = lijn tussen pixel 3 en pixel 4
		pixel prox 3 = lijn tussen pixel prox 1  en pixel 3

		pixel vericle and horizontal = pixel prox 3 
	endWhile
endWhile
```
### 3.3 Bicubic Interpolation
```C++
While next vericle pixel not last pixel
	While next horizontal pixel not last pixel

		set near vericle pixel = vericle pixel * source pixsel / size destination
		set near horizontal pixel = horizontal pixel * source pixsel / size destination

		point10 = pixel 1 = 1 pixel up near vericle pixel and near horizontal pixel
		... repeat 15 more times til rid around the source pixel

		colum 1 = take 4 pixels form the rid and check which is closer to the desired pixel 
                   and calculate based on that a wight per pixel
		... repeat an other 3 times

		value = take the results for the 4 desired and also check which is closer to the desired pixel  
                  and calculate based on that a wight per pixel.

		pixel vericle and horizontal = value
	endWhile
endWhile
```

## 4. Evaluatie 
Om tot de conclusie te komen of de scaling methoden werken en ook te kijken welke de beste keuze is, zullen er metingen gedaan moeten worden. Hierbij moet de snelheid vergeleken worden met diverse schaalfactoren, kwaliteit vergeleken worden en intergratie getest worden. Zo krijgen we een duidelijk beeld welk algoritme werkt met Arno zijn gezichtdetectie en welk algorimte welk resultaat levert.
