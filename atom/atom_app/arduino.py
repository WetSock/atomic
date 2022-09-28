from typing import List
import aiohttp
import asyncio
from threading import Thread

class Arduino():
    arduinoCommands = ["turnOff",
                        "turnOnMainLight",
                        "turnOnReactor",
                        "turnOnParogenerator",
                        "turnOnNasos",
                        "turnOnSaoz",
                        "turnOnSpzaz",
                        "turnOnKompensator",
                        "turnOnBarboter",
                        "turnOnTruboprovod",
                        "turnOnLovushka",
                        "turnOnReactorRed",
                        "turnOnParogeneratorWhite",
                        "turnOnGZNAqua",
                        "changePower",
                        "avaria"]
                        

    def asyncStart(self, scenario: str):
        demoThread = Thread(target=self.arduinoScenario, args=(scenario,))
        demoThread.start()
        return
        

    def arduinoScenario(self, scenario: str):
        
        if scenario == "Demo":
            
            asyncio.run(self.sendArduinoCommand("turnOnMainLight"))
        if scenario == "Demo1":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnReactor"))
        if scenario == "Demo2":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnParogenerator"))
        if scenario == "Demo3":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnNasos"))
        if scenario == "Demo4":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnSaoz"))
        if scenario == "Demo5":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnSpzaz"))
        if scenario == "Demo6":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnKompensator"))
        if scenario == "Demo7":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnBarboter"))
        if scenario == "Demo8":
            # Выключить всё, а затем включить нужные штуки
            asyncio.run(self.sendArduinoCommand("turnOnTruboprovod"))
            
        if scenario == "Demo9":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnLovushka"))
        if scenario == "Scenario2":
            # Выключить всё, а затем включить нужные штуки
            
            asyncio.run(self.sendArduinoCommand("turnOnReactorRed"))
            # asyncio.run(self.sendArduinoCommand("turnOnParogeneratorWhite"))
            # asyncio.run(self.sendArduinoCommand("turnOnGZNAqua"))
        if scenario == "Scenario3":
            asyncio.run(self.sendArduinoCommandWithParam("changePower","90"))
        if scenario == "Scenario4":
            asyncio.run(self.sendArduinoCommand("avaria"))
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

    async def sendArduinoCommandWithParam(self, command: str, param: str):

        if not (command in self.arduinoCommands):
            return "Передана неизвестная команда для arduino"

        async with aiohttp.ClientSession() as session:

            requestURL = f'http://192.168.2.202/?{command}&{param}&'
            try:
                async with session.get(requestURL) as resp:
                    result = await resp
                    print(result)
            except:
                print("Arduino недоступен")
                return