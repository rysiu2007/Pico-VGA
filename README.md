# RP2040 VGA Signal Generator

A bare-metal implementation of the VGA protocol (800x600 @ 60Hz) using the Raspberry Pi Pico.

### Technical Specs:
* **Overclocked Performance:** System clock set to **200MHz** for a perfect 5:1 ratio with the 40MHz pixel clock.
* **Cycle-Accurate Assembly:** Critical signal timings (HSYNC, VSYNC) implemented in **inline ARM Assembly** for rock-solid stability.
* **Direct Register Access:** Bypasses slow library calls by using SIO (Single-cycle IO) registers.
