# InDeCreaseIcons
 mod made for Geometry Dash 2.2
 u can change some stuff with ini file
 * change values of maximum icons count
 * add new search path
 * idkja

![image](https://github.com/user95401/InDeCreaseIcons/assets/90561697/20b80fff-84d1-49d9-ab85-2f5bb5629ada)

## values showcase...
```ini
[InDeCreaseIcons]

; - RUHAX TEAM, user666's original, zGuschin - explorer

; org count of Cubes 484
Cube = 484

; org count of Ships 169
Ship = 169

; org count of BALLS 118
Ball = 118

; org count of Ufos 149
Ufo = 149

; org count of Waves 96
Wave = 96

; CANT_LOAD_NEW_RES, org count of Robots 68
Robot = 68

; CANT_LOAD_NEW_RES, org count of Spiders 69
Spider = 69

; org count of Swings 43
Swing = 43

; org count of Jetpacks 5
Jetpack = 5

; NO_PATCH, org count of DeathEffects 20
DeathEffect = 20

; NO_PATCH, org count of Specials 7
Special = 7

; NO_PATCH, org count of ShipFires 6
ShipFire = 9

; u can store icon resources at "GAME_DIR/MOD_NAME/icons"
NewSearchPath = false

; load frames via "icons/_IconsSheet.plist" and "_IconsSheet.plist"
LoadCustomSpritesheet = true


[SuperUselessSettings]

; hook that function also (can uglify "special" stuff.. thatisya)
GameManager::countForType Hook = false

; 20:36:36 CE [InDeCreaseIcons]: countForType(type 0) rtn 484
GameManager::countForType Hook Logs = false

; open console at mod attach
AllocConsole = false
```
