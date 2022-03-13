# Twin-DB9-2-USB V2
a Dual db9 to usb adapter for use with TheC64 mini/maxi windows

![20220313_081459](https://user-images.githubusercontent.com/19254619/158051422-097b6ce6-38e3-4139-a87c-73822b325872.png)

The PCB has been designed to take both sizes of the pro-micro
also it has the option to use headder pins for both the buttons and controller ports for internal mounting


![schematic](https://user-images.githubusercontent.com/19254619/158052366-19a4ea35-cc3a-40ce-b49b-30a39137252d.png)

compile and upload DB9-2-USB.ino to an Pro-Micro

to add to the gamecontrollerdb.txt insert the following line at the beginning of gamecontrollerdb.txt

03000000828200000132000001010000,DB9-2-USB,a:b4,b:b5,back:b6,lefttrigger:b0,leftx:a0,lefty:a1,righttrigger:b1,start:b7,x:b3,y:b2,platform:Linux,

the above line(s) are 1 line of text in gamecontrollerdb.txt


Licence.

Copyright (C) 2020 Gary Metheringham

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

This notice may not be removed or altered from any source distribution.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
