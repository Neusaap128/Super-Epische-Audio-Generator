- - -


### Onderwerp 
We gaan voor ons IB3 project een audio effect generator maken. We zijn 3 elektronica-ICT studenten, we bouwen dit project verder op onze reeds vergaarde kennis van een voorgaand vak namelijk Digital Signal Processing (DSP). We gaan een audio signaal binnen lezen, dit signaal dan vervormen aan de hand van filters en terug naar buiten brengen via een audio jack.


### Probleem omschrijving
Niet gemoduleerde instrument klanken kunnen eentonig klinken. Om dit op te lossen gaan we aan de hand van DSP de audio transformeren. We willen een gemakkelijke user interface hebben waarmee je eenvoudig de effecten kunt instellen. 

Wanneer de audio luid en duidelijk hoorbaar is door een speaker, na vervorming, kunnen we spreken van een geslaagd project!

### Technische beschrijving
Voor de audio wordt ingelezen wordt deze gebuffered en gefiltert. De audio digitaliseren we via een codec, deze sampled de audio naar 24 bit waarden. Deze worden vervolgens doorgestuurd naar een STM32 controller via I²S verbinding. De codec wordt ingesteld via I²C. De STM32 microcontroller doet DSP om de audio te vervormen. Vervolgens word de vervormende digitale audio terug gestuurd naar de codec, dia het via een Digital Analog Converter (DAC) terug omzet naar een hoorbaar electrisch signaal.
