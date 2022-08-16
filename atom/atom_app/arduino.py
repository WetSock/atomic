from typing import List
import aiohttp
import asyncio

class Arduino():
    arduinoCommands = ["turnOff",
                        "setAqua",
                        "setYellow"]

    def arduinoScenario(self, scenario: int):
        
        if scenario == 1:
            asyncio.run(self.sendArduinoCommand("turnOff"))
        if scenario == 2:
            asyncio.run(self.sendArduinoCommand("setAqua"))
        if scenario == 3:
            asyncio.run(self.sendArduinoCommand("setYellow"))
        return

    async def sendArduinoCommand(self, command: str):

        if not (command in self.arduinoCommands):
            return

        async with aiohttp.ClientSession() as session:

            requestURL = f'http://192.168.2.202/?{command}'
            async with session.get(requestURL) as resp:
                pokemon = await resp
                print(pokemon)

        
arduino = Arduino()
arduino.arduinoScenario(1)
arduino.arduinoScenario(2)