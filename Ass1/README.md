# Epidemic Models Simulation

This repository contains a Python implementation of three common epidemiological models: **SI**, **SIR**, and a **Two-Factor Model**. These models simulate the spread of infectious diseases through a population using differential equations.

## **Models Overview**

### 1. **SI Model**
The SI (Susceptible-Infected) model divides the population into two compartments:
- **Susceptible (S):** Individuals who can be infected.
- **Infected (I):** Individuals who are infected and can spread the disease.

The rate of infection depends on the number of susceptible and infected individuals.

---

### 2. **SIR Model**
The SIR (Susceptible-Infected-Recovered) model expands on the SI model by adding a **Recovered (R)** compartment:
- **Susceptible (S):** Individuals who can be infected.
- **Infected (I):** Individuals who are infected and can spread the disease.
- **Recovered (R):** Individuals who have recovered and are immune to the disease.

The model includes a recovery rate (`gamma`) that moves individuals from the infected to the recovered compartment.

---

### 3. **Two-Factor Model**
This model introduces an additional **Exposed (E)** compartment to capture latent periods in disease progression:
- **Susceptible (S):** Individuals who can be infected.
- **Exposed (E):** Individuals who are infected but not yet infectious.
- **Infected (I):** Individuals who are actively infectious.

It accounts for:
- Birth and natural death rates (`mu`).
- Transition rates between compartments (`beta`, `etha`, `gamma`).


---

## **Dependencies**
This code requires the following Python libraries:
- `numpy`: For numerical computations.
- `matplotlib`: For plotting the results.

Install them using pip:
```bash
pip install numpy matplotlib
```

---

## **Output**
The code produces a set of three plots:
1. **SI Model:** Tracks Susceptible and Infected populations over time.
2. **SIR Model:** Tracks Susceptible, Infected, and Recovered populations over time.
3. **Two-Factor Model:** Tracks Susceptible, Exposed, and Infected populations over time.


