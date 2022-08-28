from typing import List
import aiohttp
import asyncio
from threading import Thread

class Arduino():
    arduinoCommands = ["turnOff",
                        "setAqua",
                        "setYellow"]
                        

    def asyncStart(self, scenario: str):
        demoThread = Thread(target=self.arduinoScenario, args=(scenario,))
        demoThread.start()
        return
        

    def arduinoScenario(self, scenario: str):
        
        if scenario == "Demo":
            asyncio.run(self.sendArduinoCommand("turnOff"))
        if scenario == "Demo1":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setAqua"))
        if scenario == "Demo2":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setYellow"))
        if scenario == "Demo3":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setYellow"))
        if scenario == "Demo4":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setYellow"))
        if scenario == "Demo5":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setYellow"))
        if scenario == "Demo6":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setYellow"))
        if scenario == "Demo7":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setYellow"))
        if scenario == "Demo8":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setYellow"))
        if scenario == "Demo9":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOff"))
            asyncio.run(self.sendArduinoCommand("setYellow"))
        return

    async def sendArduinoCommand(self, command: str):

        if not (command in self.arduinoCommands):
            return "Передана неизвестная команда для arduino"

        async with aiohttp.ClientSession() as session:

            requestURL = f'http://192.168.2.202/?{command}'
            try:
                async with session.get(requestURL) as resp:
                    result = await resp
                    print(result)
            except:
                print("Arduino недоступен")
                return

        