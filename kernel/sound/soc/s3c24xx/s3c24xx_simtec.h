

extern void simtec_audio_init(struct snd_soc_codec *codec);

extern int simtec_audio_core_probe(struct platform_device *pdev,
				   struct snd_soc_device *socdev);

extern int simtec_audio_remove(struct platform_device *pdev);

#ifdef CONFIG_PM
extern const struct dev_pm_ops simtec_audio_pmops;
#define simtec_audio_pm &simtec_audio_pmops
#else
#define simtec_audio_pm NULL
#endif
