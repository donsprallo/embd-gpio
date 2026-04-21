#ifndef EMBD_GPIO_H
#define EMBD_GPIO_H

/// @brief An abstract GPIO object that can be used to handle a single GPIO pin.
/// An instance of an `embd_gpio_t` pin can be used with the module functions
/// `gpio_set`, `gpio_get` and `gpio_toggle`.
typedef struct embd_gpio embd_gpio_t;

/// The state of an GPIO pin.
typedef enum {
  EMBD_GPIO_STATE_ACTIVE,
  EMBD_GPIO_STATE_INACTIVE,
} embd_gpio_state_t;

/// @brief The GPIO pin interface. An GPIO device driver must implement the
/// interface to handle the module functions `gpio_set`, `gpio_get` and
/// `gpio_toggle`.
typedef struct {
  void (*set)(const void *self, embd_gpio_state_t value);
  embd_gpio_state_t (*get)(const void *self);
  void (*toggle)(const void *self);
} embd_gpio_interface_t;

struct embd_gpio {
  const embd_gpio_interface_t *vtable;
  void *instance;
};

/// @brief Set an GPIO output pin to a value.
/// @param gpio The GPIO pin to set.
/// @param value The value to set.
static inline void gpio_set(const embd_gpio_t *gpio, const embd_gpio_state_t value) {
  gpio->vtable->set(gpio->instance, value);
}

/// @brief Get the current state of an GPIO pin.
/// @param gpio The GPIO pin to get.
/// @return the current GPIO pin state.
static inline embd_gpio_state_t gpio_get(const embd_gpio_t *gpio) {
  return gpio->vtable->get(gpio->instance);
}

/// @brief Toggle the state of an GPIO pin.
/// @param gpio The GPIO pin to toggle.
static inline void gpio_toggle(const embd_gpio_t *gpio) {
  gpio->vtable->toggle(gpio->instance);
}

#endif // EMBD_GPIO_H
