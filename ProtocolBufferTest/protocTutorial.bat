@echo work
protoc -I=%~dp0 --cpp_out=%~dp0 %~dp0/tutorial.Person.proto