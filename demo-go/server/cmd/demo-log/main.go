package main

import (
	"github.com/rs/zerolog"
	"github.com/rs/zerolog/log"
	"gopkg.in/natefinch/lumberjack.v2"
	"os"
	"time"
)

func init() {
	logInit()
}

func main() {
	logTest()
}

func logTest() {
	log.Trace().Msg("This is a trace message")
	log.Debug().Msg("This is a debug message")
	log.Info().Msg("Hello World!")
	log.Warn().Msg("This is a warning message")
	log.Error().Msg("This is an error message")
	go logPanicTest()
	for {
		log.Trace().Msg("Another log for rotate test")
		time.Sleep(5 * time.Millisecond)
	}
}

func logPanicTest() {
	defer func() {
		if r := recover(); r != nil {
			log.Warn().Any("panic_msg", r).Msg("Recovered from panic")
		}
	}()
	log.Panic().Msg("PANIC LOG")
}

func logInit() {
	path := "/tmp/demo.log"
	verbose := lumberjack.Logger{
		Filename:   path,
		MaxSize:    1, // megabytes
		MaxBackups: 5,
		Compress:   true,
	}
	if _, err := os.Stat(path); err == nil {
		_ = verbose.Rotate()
	}
	zerolog.SetGlobalLevel(zerolog.TraceLevel)
	console := zerolog.ConsoleWriter{
		Out:        os.Stderr,
		TimeFormat: time.RFC3339,
	}
	threshold := ThresholdWriter{
		writer:    zerolog.MultiLevelWriter(console),
		threshold: zerolog.WarnLevel,
	}
	multi := zerolog.MultiLevelWriter(&verbose, &threshold)
	log.Logger = log.Output(multi)
}

type ThresholdWriter struct {
	threshold zerolog.Level
	writer    zerolog.LevelWriter
}

func (t *ThresholdWriter) Write(bytes []byte) (n int, err error) {
	return t.writer.Write(bytes)
}

func (t *ThresholdWriter) WriteLevel(level zerolog.Level, bytes []byte) (n int, err error) {
	if level >= t.threshold {
		return t.writer.WriteLevel(level, bytes)
	}
	return len(bytes), nil
}
