t = 0:0.01:10; % Time vector
x = sin(2*pi*5*t) + sin(2*pi*10*t); % Signal with two sinusoidal components

y = fft(x); % Compute the Fourier transform of the signal
n = length(x); % Length of signal
f = (0:n-1)*(1/(n*0.01)); % Frequency vector

% Plot the signal and its Fourier transform
subplot(2,1,1);
plot(t, x);
xlabel('Time');
ylabel('Amplitude');
title('Original signal');

subplot(2,1,2);
plot(f, abs(y));
xlabel('Frequency');
ylabel('Magnitude');
title('Magnitude spectrum of the signal');