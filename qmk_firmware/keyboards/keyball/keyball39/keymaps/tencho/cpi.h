
#pragma once

// ref:https://mazcon.hatenablog.com/entry/2023/11/10/080000

#define PRECISION_CPI_LOW 1
#define SCROLL_DIV_LOW 64

static uint16_t latest_cpi = 1;
static uint16_t latest_scroll_div = 7;
static bool cpi_state  = false;

void precision_toggle(bool pressed) {
    if (!pressed) {
        return;
    }

    // CPI 更新
    uint16_t current_cpi = keyball_get_cpi();
    if(!cpi_state && latest_cpi != current_cpi) {
        latest_cpi = current_cpi;
    }

    uint16_t current_scroll_div = keyball_get_scroll_div();
    if(cpi_state && latest_scroll_div != current_scroll_div) {
        latest_scroll_div = current_scroll_div;
    }

    uint16_t cpi = cpi_state ? latest_cpi : PRECISION_CPI_LOW;
    keyball_set_cpi(cpi);

    uint16_t scroll_div = cpi_state ? latest_scroll_div : SCROLL_DIV_LOW;
    keyball_set_scroll_div(scroll_div);

    cpi_state = !cpi_state;
}
