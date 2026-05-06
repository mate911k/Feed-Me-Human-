# Arduino alapú automata etető projekt

## Projekt leírása

Ez a projekt egy Arduino Uno alapú automata etetőrendszer szimulációja, amely Tinkercad környezetben készült.  
A rendszer célja egy egyszerű, de jól követhető etetési folyamat megvalósítása, ahol egy potméter segítségével betudjuk állítani az etetés időtartamát, majd egy nyomógombbal eltudjuk indítani a folyamatot.

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

### `dokumentacio` mappa

Ebben a mappában található a projekt dokumentációja.  
A dokumentáció részletesebben bemutatja a projekt célját, az alkatrészeket, a kapcsolást, a program működését, valamint a tesztelés során szerzett tapasztalatokat.

### `kepek` mappa

Ebben a mappában találhatók a projekthez tartozó képek, például a kapcsolási rajz, a Tinkercad szimuláció képernyőképei és egyéb ábrák.

## Összegzés

A projekt célja egy egyszerű, Arduino alapú automata etetőrendszer elkészítése volt.  
A végeredmény egy működő szimuláció lett, amely képes időzített etetési folyamatot végrehajtani, közben pedig vizuális és hangalapú visszajelzést is ad.
