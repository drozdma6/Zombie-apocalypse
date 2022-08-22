#Zombie Apocalypse
Hra spočíva v prežití, respektíve zabití čo najviac zombíkov (hra počíta aktuálne skóre). Ak sa vytvára nová hra tak si hráč
nastaví atribúty postavy (meno, životy, počet teleportov). Ak mal hru vopred uloženú, tak sa načíta rozohraná hra zo súboru.

**Príkazy aplikácie:**
- `new`  vytvorí novú hru, nasleduje vytvorenie postavy,
- `load` načíta hru zo súboru,
- `quit` ukončí program.

Po vytvorení postavy sa začína hra. Zo súboru sa načíta mapa.

###Mapa:
```
+--------- -+
| >      #  |
|B    #     |
|         #+|
|  G     ZZ |
|    #  Z ##|
|    #     +|
+-----------+

Legenda:
> player
Z Zombie
G Gun
B Bomb
| Vertikal wall
- Horizontal wall
# Inside wall
+ Zombie spawn
```
Hráč sa vie pohybovať po mape príkazmi do konzole.

**Pohyb:**
- `s` dole,
- `a` dolava,
- `w` hore,
- `d` doprava.

**Schopnosti:**
- `p` slúži na teleportovanie vpred, až do narazenia o hranu. (tj #, |, -) alebo o zombie spawn (tj +).

V bludisku sa budú na náhodných políčkach zobrazovať zbrane (gun, bomb), ktoré
si vie hráč vziať prídením na dané políčko,a tým si ich vie pridať do inventáru a následne
vie nimi zabíjať zombíkov.

Hráč má jednu aktívnu zbraň, tj zbraň, ktorú aktuálne používa, je označená <--.
Aktívne zbrane si vie hráč meniť, na toto slúži príkaz:
- `e`.

Na následné použitie zbrane (vystrelenie) slúži príkaz:
- `f`.

Každý zabitý zombík pridáva hráčovi skóre.
Ak je zombík a hráč na rovnakom políčku, tak sa hráčóvi uberá život, a zombik umiera. Hra končí keď má hráč nula životov
alebo využitím príkazu `q`, ktorým sa ukončí aktuálny beh hry a užívatelovi sa ponúka možnosť na uloženie hry.
