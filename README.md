# Arduino alapú automata etető projekt

## Projekt leírása

Ez a projekt egy Arduino Uno alapú automata etetőrendszer szimulációja, amely Tinkercad környezetben készült.  
A rendszer célja egy egyszerű, de jól követhető etetési folyamat megvalósítása, ahol a felhasználó egy potméter segítségével be tudja állítani az etetés időtartamát, majd egy nyomógombbal el tudja indítani a folyamatot.

A projekt több visszajelzési formát is használ. Az aktuális állapotot LED-ek jelzik, az LCD kijelző szöveges információt ad a működésről, a piezo hangjelző hanggal jelez, a szervómotor pedig az etetőtál fedelének nyitását és zárását szimulálja.

## Fő funkciók

- Potméterrel állítható etetési idő
- Nyomógombbal indítható működés
- LCD kijelzőn megjelenő állapotinformációk
- LED-es visszajelzés a különböző fázisokhoz
- Hangjelzések az egyes állapotoknál
- Szervómotoros nyitás és zárás
- Visszaszámlálás az etetési folyamat közben

## Működési állapotok

A rendszer három fő állapotot használ:

1. **VARAKOZAS**  
   Alapállapot. A piros LED világít, az LCD kijelző pedig mutatja a potméterrel beállított időt.

2. **HAMAROSAN**  
   A gomb megnyomása után induló figyelmeztető állapot. Ekkor a sárga LED világít, a kijelzőn megjelenik a figyelmeztető szöveg, és hangjelzés is hallható.

3. **EHET**  
   Az aktív etetési állapot. A szervómotor kinyitja az etetőt, a zöld LED villog, az LCD kijelző pedig visszaszámolja a hátralévő időt.

A beállított idő letelte után a szervómotor visszazárja az etetőt, majd a rendszer visszatér alapállapotba.

## Felhasznált alkatrészek

- Arduino Uno
- Breadboard
- 16x2 LCD kijelző
- Szervómotor
- Potméter
- Nyomógomb
- Piezo hangjelző
- Piros LED
- Sárga LED
- Zöld LED
- Ellenállások
- Jumper vezetékek

## Projekt fájljai

A repositoryban a projekt fájljai mappákba rendezve találhatók.

### `kod` mappa

Ebben a mappában található az Arduino forráskód `.ino` fájlként.  
A kód vezérli a LED-eket, az LCD kijelzőt, a nyomógombot, a potmétert, a piezo hangjelzőt és a szervómotort.

### `dokumentacio` mappa

Ebben a mappában található a projekt dokumentációja.  
A dokumentáció részletesebben bemutatja a projekt célját, az alkatrészeket, a kapcsolást, a program működését, valamint a tesztelés során szerzett tapasztalatokat.

### `kepek` mappa

Ebben a mappában találhatók a projekthez tartozó képek, például a kapcsolási rajz, a Tinkercad szimuláció képernyőképei és egyéb ábrák.

## A program rövid ismertetése

A program az Arduino alapvető felépítését követi.  
A `setup()` részben történnek a kezdeti beállítások, például a pinek megadása, az LCD kijelző indítása és a szervómotor alaphelyzetbe állítása.

A `loop()` rész folyamatosan figyeli a potméter értékét és a nyomógomb állapotát.  
Ha a felhasználó megnyomja a gombot, a program elindítja az etetési folyamatot. Először figyelmeztető állapot következik, majd a szervómotor kinyitja az etetőt. Ezután elindul a visszaszámlálás, közben a zöld LED villog. A folyamat végén a szervómotor visszazárja az etetőt, majd a rendszer visszatér várakozási állapotba.

A kód több külön függvényre van bontva, hogy átláthatóbb legyen. Külön függvény kezeli például a LED-ek kikapcsolását, a hangjelzéseket, a szervómotor mozgatását, a gomb érzékelését és a potméter értékének frissítését.

## Tesztelés és tapasztalatok

A projekt fejlesztése során több kisebb hibát is javítani kellett.  
A gomb érzékelésénél fontos volt, hogy a rendszer ne induljon el véletlenül, illetve a gombnyomást megbízhatóan érzékelje. A potméter frissítésénél szintén szükség volt finomításra, mert túl gyakori frissítés esetén a Tinkercad szimuláció lassabbnak tűnt.

A tesztelés során az is kiderült, hogy a vezetékezés elrendezése hatással lehet a szimuláció stabilitására. A végleges változatban a kapcsolás és a kód is úgy lett kialakítva, hogy a működés egyszerű, átlátható és stabil legyen.

## Összegzés

A projekt célja egy egyszerű, Arduino alapú automata etetőrendszer elkészítése volt.  
A végeredmény egy működő szimuláció lett, amely képes időzített etetési folyamatot végrehajtani, közben pedig vizuális és hangalapú visszajelzést is ad.

A projekt elkészítése során gyakorlati tapasztalatot szereztem az Arduino programozásában, a bemenetek és kimenetek kezelésében, az LCD kijelző használatában, valamint a szervómotor és a potméter vezérlésében.
